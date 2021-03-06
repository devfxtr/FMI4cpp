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

#include <fmi4cpp/fmi2/import/ModelExchangeInstance.hpp>

using namespace fmi4cpp::fmi2;

ModelExchangeInstance::ModelExchangeInstance(const fmi2Component c,
                                             const std::shared_ptr<ModelExchangeLibrary> &library,
                                             const std::shared_ptr<ModelExchangeModelDescription> &modelDescription)
        : AbstractFmuInstance<ModelExchangeLibrary, ModelExchangeModelDescription>(c, library, modelDescription) {}

bool ModelExchangeInstance::enterEventMode() {
    return library_->enterEventMode(c_);
}

bool ModelExchangeInstance::enterContinuousTimeMode() {
    return library_->enterContinuousTimeMode(c_);
}

bool ModelExchangeInstance::setTime(const double time) {
    this->simulationTime_ = time;
    return library_->setTime(c_, time);
}

bool ModelExchangeInstance::setContinuousStates(const std::vector<fmi2Real> &x) {
    return library_->setContinuousStates(c_, x);
}

bool ModelExchangeInstance::getDerivatives(std::vector<fmi2Real> &derivatives) {
    return library_->getDerivatives(c_, derivatives);
}

bool ModelExchangeInstance::getEventIndicators(std::vector<fmi2Real> &eventIndicators) {
    return library_->getEventIndicators(c_, eventIndicators);
}

bool ModelExchangeInstance::getContinuousStates(std::vector<fmi2Real> &x) {
    return library_->getContinuousStates(c_, x);
}

bool ModelExchangeInstance::getNominalsOfContinuousStates(std::vector<fmi2Real> &x_nominal) {
    return library_->getNominalsOfContinuousStates(c_, x_nominal);
}

bool ModelExchangeInstance::completedIntegratorStep(
        fmi2Boolean noSetFMUStatePriorToCurrentPoint,
        fmi2Boolean &enterEventMode,
        fmi2Boolean &terminateSimulation) {
    return library_->completedIntegratorStep(c_, noSetFMUStatePriorToCurrentPoint, enterEventMode, terminateSimulation);
}

bool ModelExchangeInstance::newDiscreteStates() {
    return library_->newDiscreteStates(c_, eventInfo_);
}
