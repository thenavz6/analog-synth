/*
  ==============================================================================

    SynthVoice.h
    Created: 28 Aug 2020 1:44:41pm
    Author:  navan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include <iostream>
#include <stdio.h>
#include "src/maximilian.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:

    virtual bool 	canPlaySound(juce::SynthesiserSound* sound)
    {
        return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
    }

    void setOscType(std::atomic<float>* choice) {
        waveType = *choice;
    }

    double getOscType() {
        switch (waveType) {
        case 0:
            return osc1.sinewave(frequency);
        case 1:
            return osc1.saw(frequency);
        case 2:
            return osc1.square(frequency);
        default:
            return osc1.sinewave(frequency);
        }
    }

    void setEnvParams(std::atomic<float>* attack, std::atomic<float>* decay, std::atomic<float>* sustain, std::atomic<float>* release)
    {
        env1.setAttack(*attack);
        env1.setDecay(*decay);
        env1.setSustain(*sustain);
        env1.setRelease(*release);
    }

    double getEnv()
    {
        return env1.adsr(getOscType(), env1.trigger) * level;
    }

    void setFilterParams(std::atomic<float>* type, std::atomic<float>* cutOff, std::atomic<float>* res)
    {
        filterType = *type;
        filterCutOff = *cutOff;
        filterResonance = *res;
    }

    double getFilter() {
        switch (filterType) {
        case 0:
            return fil1.lores(getEnv(), filterCutOff, filterResonance);
        case 1:
            return fil1.bandpass(getEnv(), filterCutOff, filterResonance);
        case 2:
            return fil1.hires(getEnv(), filterCutOff, filterResonance);
        default:
            return fil1.lores(getEnv(), filterCutOff, filterResonance);
        }
    }

    virtual void 	startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        env1.trigger = 1;
        level = velocity;
        frequency =  juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    }

    virtual void 	stopNote(float velocity, bool allowTailOff)
    {
        env1.trigger = 0;
        allowTailOff = true;

        if (velocity == 0) {
            clearCurrentNote();
        }
        
    }

    virtual void 	pitchWheelMoved(int newPitchWheelValue)
    {}

    virtual void 	controllerMoved(int controllerNumber, int newControllerValue)
    {}

    virtual void 	renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples)
    {

        for (auto sample = 0; sample < numSamples; ++sample) {
            for (auto channel = 0; channel < outputBuffer.getNumChannels(); ++channel) {
                outputBuffer.addSample(channel, startSample, getFilter());
            }
            ++startSample;
        }
    }

private:

    double level;
    double frequency;
    int waveType;

    int filterType;
    double filterCutOff;
    double filterResonance;

    maxiOsc osc1;
    maxiEnv env1;
    maxiFilter fil1;


};
