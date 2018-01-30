# node-kpathsea (`node-kpathsea`)

Node native bindings to the [Kpathsea](https://tug.org/kpathsea/) library

# Installation

```
npm install node-kpathsea
```

Building the native module requires you having the Kpathsea library and
includes on your machine (which probably means you need some version of TeX
Live installed).

# Usage

```
import {Kpathsea, FILE_FORMAT} from "node-kpathsea";

const kpse = new Kpathsea("/usr/bin/tex");

kpse.findFile("cmr10", FILE_FORMAT.TFM)
// -> "/usr/share/texmf-dist/fonts/tfm/public/cm/cmr10.tfm"
```

# License

MIT
