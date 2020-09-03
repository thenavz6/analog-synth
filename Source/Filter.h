/*
  ==============================================================================

    Filter.h
    Created: 31 Aug 2020 8:42:03pm
    Author:  navan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Filter  : public juce::Component
{
public:
    Filter(SynthFrameworkAudioProcessor&);
    ~Filter() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& audioProcessor;

    juce::Slider filterCutOffSlider;
    juce::Slider filterResonanceSlider;
    juce::ComboBox filterTypeMenu;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> cutOffTree;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> resonanceTree;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeTree;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filter)
};
