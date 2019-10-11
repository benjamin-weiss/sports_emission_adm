# Sports Emission ADM

This is a simple example on how to create a multi language + audio description
ADM file using `libadm`.

The `sports_emission_stage_01.pdf` is created using a adm graph tool based on
the `ebu_adm_renderer`. You can find it
[here](https://github.com/benjamin-weiss/ebu_adm_renderer/tree/graph-adm-tool).

## Build instructions

Building should be quite straight forward. Just ensure, that you clone the
repository using the `--recursive` flag.

```
git clone --recursive git@github.com:benjamin-weiss/sports_emission_adm.git
cd sports_emission_adm
mkdir build && cd build
cmake ..
make
make install
```

## License

```
Copyright 2019 Benjamin Weiss

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
```
