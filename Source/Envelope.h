/*
  ==============================================================================

    Envelope.h
    Created: 29 Aug 2020 7:39:20pm
    Author:  navan

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Envelope  : public juce::Component, public juce::Slider::Listener
{
public:
    Envelope(SynthFrameworkAudioProcessor&);
    ~Envelope() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider*) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthFrameworkAudioProcessor& audioProcessor;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attackTree;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> decayTree;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sustainTree;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> releaseTree;

    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
