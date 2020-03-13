# lcgcrack

Linear Congruential Generator cracker for ALEXCTF 2017's Crypto5 challenge.

This approach differs from the others in that it does not attempt to find the period of the LCG (which depending on the scenario can be quite a difficult task), but instead solves the congruence system to get the coefficients.

The challenge is to crack a remote PRNG that leaks its next values.
Writeup can be found at `@todo`.

The `lcg` folder contains a reconstruction of the specific LCG used for the challenge.

This LCG is the one used in `lcgcrack.py`, although for the challenge source code was not provided.

# License
The MIT License (MIT)

Copyright (c) 2017 Artur Marzano

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPY
