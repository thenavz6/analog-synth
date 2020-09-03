/*
  ==============================================================================

    Oscillator.h
    Created: 29 Aug 2020 6:08:05pm
    Author:  navan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Oscillator  : public juce::Component,
    public juce::ComboBox::Listener
{
public:
    Oscillator(SynthFrameworkAudioProcessor&);
    ~Oscillator() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void comboBoxChanged(juce::ComboBox*) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& audioProcessor;

    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscMenuTree;

    juce::ComboBox oscMenu;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
