/*
 * The MIT License
 *
 * Copyright 2017-2018 Norwegian University of Technology
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef FMI4CPP_STATUS_CONVERTER_HPP
#define FMI4CPP_STATUS_CONVERTER_HPP

#include <fmi4cpp/fmi2/import/Status.hpp>
#include <fmi4cpp/fmi2/fmi2FunctionTypes.h>

namespace fmi4cpp::fmi2 {

    inline Status convert(fmi2Status status) {

        switch (status) {
            case fmi2OK:
                return Status::OK;
            case fmi2Warning:
                return Status::Warning;
            case fmi2Discard:
                return Status::Discard;
            case fmi2Error:
                return Status::Error;
            case fmi2Fatal:
                return Status::Fatal;
            case fmi2Pending:
                return Status::Pending;
        }

    }

}

#endif //FMI4CPP_STATUS_CONVERTER_HPP
