/*
MIT License

Copyright (c) 2018 Brian T. Park

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef AUNIT_TEST_AGAIN_H
#define AUNIT_TEST_AGAIN_H

#include <stdint.h>
#include "FCString.h"
#include "MetaAssertion.h"

namespace aunit {

/** Similar to TestOnce but performs the user-defined test multiple times. */
class TestAgain: public MetaAssertion {
  public:
    /** Constructor. */
    TestAgain() {}

    /**
     * Calls the user-provided again() method multiple times until the user
     * code explicitly resolves the test using pass(), fail(), skip() or
     * expire().
     */
    void loop() override;

    /** User-provided test case. */
    virtual void again() = 0;

  private:
    // Disable copy-constructor and assignment operator
    TestAgain(const TestAgain&) = delete;
    TestAgain& operator=(const TestAgain&) = delete;
};

}

#endif
