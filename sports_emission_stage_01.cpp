#include <iostream>
#include <sstream>
#include "adm/adm.hpp"
#include "adm/utilities/id_assignment.hpp"
#include "adm/utilities/object_creation.hpp"
#include "adm/write.hpp"
#include "adm/common_definitions.hpp"

int main() {
  using namespace adm;

  // create Document
  auto document = Document::create();
  addCommonDefinitionsTo(document);

  // create ADM elements
  auto programmeEn = AudioProgramme::create(AudioProgrammeName("Programme En"));
  auto programmeDe = AudioProgramme::create(AudioProgrammeName("Programme De"));
  auto programmeFr = AudioProgramme::create(AudioProgrammeName("Programme Fr"));
  auto programmeIt = AudioProgramme::create(AudioProgrammeName("Programme It"));
  auto programmeEnAD =
      AudioProgramme::create(AudioProgrammeName("Programme En AD"));
  auto programmeDeAD =
      AudioProgramme::create(AudioProgrammeName("Programme De AD"));
  auto programmeFrAD =
      AudioProgramme::create(AudioProgrammeName("Programme Fr AD"));
  auto programmeItAD =
      AudioProgramme::create(AudioProgrammeName("Programme It AD"));

  auto contentEn = AudioContent::create(AudioContentName("English"),
                                        AudioContentLanguage("en"));
  auto contentDe = AudioContent::create(AudioContentName("German"),
                                        AudioContentLanguage("de"));
  auto contentFr = AudioContent::create(AudioContentName("French"),
                                        AudioContentLanguage("fr"));
  auto contentIt = AudioContent::create(AudioContentName("Italian"),
                                        AudioContentLanguage("it"));
  auto contentEnAD = AudioContent::create(AudioContentName("English AD"),
                                          AudioContentLanguage("en"),
                                          DialogueContent::AUDIO_DESCRIPTION);
  auto contentDeAD = AudioContent::create(AudioContentName("German AD"),
                                          AudioContentLanguage("de"),
                                          DialogueContent::AUDIO_DESCRIPTION);
  auto contentFrAD = AudioContent::create(AudioContentName("French AD"),
                                          AudioContentLanguage("fr"),
                                          DialogueContent::AUDIO_DESCRIPTION);
  auto contentItAD = AudioContent::create(AudioContentName("Italian AD"),
                                          AudioContentLanguage("it"),
                                          DialogueContent::AUDIO_DESCRIPTION);
  auto contentCrowd = AudioContent::create(AudioContentName("Crowd"));

  programmeEn->addReference(contentEn);
  programmeDe->addReference(contentDe);
  programmeFr->addReference(contentFr);
  programmeIt->addReference(contentIt);
  programmeEn->addReference(contentCrowd);
  programmeDe->addReference(contentCrowd);
  programmeFr->addReference(contentCrowd);
  programmeIt->addReference(contentCrowd);

  programmeEnAD->addReference(contentEn);
  programmeDeAD->addReference(contentDe);
  programmeFrAD->addReference(contentFr);
  programmeItAD->addReference(contentIt);
  programmeEnAD->addReference(contentEnAD);
  programmeDeAD->addReference(contentDeAD);
  programmeFrAD->addReference(contentFrAD);
  programmeItAD->addReference(contentItAD);
  programmeEnAD->addReference(contentCrowd);
  programmeDeAD->addReference(contentCrowd);
  programmeFrAD->addReference(contentCrowd);
  programmeItAD->addReference(contentCrowd);

  SimpleObjectHolder holder;
  auto groupingObjectEn = AudioObject::create(AudioObjectName("En"));
  holder = createSimpleObject("En 01");
  holder.audioChannelFormat->add(AudioBlockFormatObjects(SphericalPosition()));
  groupingObjectEn->addReference(holder.audioObject);
  holder = createSimpleObject("En 02");
  holder.audioChannelFormat->add(AudioBlockFormatObjects(SphericalPosition()));
  groupingObjectEn->addReference(holder.audioObject);
  contentEn->addReference(groupingObjectEn);

  holder = createSimpleObject("En AD");
  holder.audioChannelFormat->add(AudioBlockFormatObjects(SphericalPosition()));
  contentEnAD->addReference(holder.audioObject);

  auto groupingObjectDe = AudioObject::create(AudioObjectName("De"));
  holder = createSimpleObject("De 01");
  holder.audioChannelFormat->add(AudioBlockFormatObjects(SphericalPosition()));
  groupingObjectDe->addReference(holder.audioObject);
  holder = createSimpleObject("De 02");
  holder.audioChannelFormat->add(AudioBlockFormatObjects(SphericalPosition()));
  groupingObjectDe->addReference(holder.audioObject);
  contentDe->addReference(groupingObjectDe);

  holder = createSimpleObject("De AD");
  holder.audioChannelFormat->add(AudioBlockFormatObjects(SphericalPosition()));
  contentDeAD->addReference(holder.audioObject);

  auto groupingObjectFr = AudioObject::create(AudioObjectName("Fr"));
  holder = createSimpleObject("Fr 01");
  holder.audioChannelFormat->add(AudioBlockFormatObjects(SphericalPosition()));
  groupingObjectFr->addReference(holder.audioObject);
  holder = createSimpleObject("Fr 02");
  holder.audioChannelFormat->add(AudioBlockFormatObjects(SphericalPosition()));
  groupingObjectFr->addReference(holder.audioObject);
  contentFr->addReference(groupingObjectFr);

  holder = createSimpleObject("Fr AD");
  holder.audioChannelFormat->add(AudioBlockFormatObjects(SphericalPosition()));
  contentFrAD->addReference(holder.audioObject);

  auto groupingObjectIt = AudioObject::create(AudioObjectName("It"));
  holder = createSimpleObject("It 01");
  holder.audioChannelFormat->add(AudioBlockFormatObjects(SphericalPosition()));
  groupingObjectIt->addReference(holder.audioObject);
  holder = createSimpleObject("It 02");
  holder.audioChannelFormat->add(AudioBlockFormatObjects(SphericalPosition()));
  groupingObjectIt->addReference(holder.audioObject);
  contentIt->addReference(groupingObjectIt);

  holder = createSimpleObject("It AD");
  holder.audioChannelFormat->add(AudioBlockFormatObjects(SphericalPosition()));
  contentItAD->addReference(holder.audioObject);

  // groupingObjectEn->addComplementary(groupingObjectDe);
  // groupingObjectEn->addComplementary(groupingObjectFr);
  // groupingObjectEn->addComplementary(groupingObjectIt);

  auto channelbedHolder = addChannelBedObjectTo(document, "Crowd", "0+5+0");
  contentCrowd->addReference(channelbedHolder.audioObject);

  document->add(programmeEn);
  document->add(programmeDe);
  document->add(programmeFr);
  document->add(programmeIt);
  document->add(programmeEnAD);
  document->add(programmeDeAD);
  document->add(programmeFrAD);
  document->add(programmeItAD);
  reassignIds(document);

  // write XML data to stdout
  std::stringstream xmlStream;
  writeXml(xmlStream, document);
  std::cout << xmlStream.str();
  return 0;
}
