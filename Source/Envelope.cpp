/*
  ==============================================================================

    Envelope.cpp
    Created: 29 Aug 2020 7:39:20pm
    Author:  navan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(SynthFrameworkAudioProcessor& p) : audioProcessor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    attackSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20.0, 10.0);
    attackSlider.addListener(this);
    addAndMakeVisible(&attackSlider);

    decaySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    decaySlider.setRange(0.1f, 5000.0f);
    decaySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20.0, 10.0);
    decaySlider.addListener(this);
    addAndMakeVisible(&decaySlider);

    sustainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    sustainSlider.setRange(-60.0f, 0.0f);
    sustainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20.0, 10.0);
    sustainSlider.addListener(this);
    addAndMakeVisible(&sustainSlider);

    releaseSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    releaseSlider.setRange(0.1f, 5000.0f);
    releaseSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 20.0, 10.0);
    releaseSlider.addListener(this);
    addAndMakeVisible(&releaseSlider);

    attackTree = make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "attack", attackSlider);
    decayTree = make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "decay", decaySlider);
    sustainTree = make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "sustain", sustainSlider);
    releaseTree = make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "release", releaseSlider);

}

Envelope::~Envelope()
{
}

void Envelope::paint (juce::Graphics& g)
{
    
}

void Envelope::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    //draws the sliders...we use a rectangle object to dynamically size the UI (if we want to resize for IPad etc without needing to change ALL settings
    juce::Rectangle<int> area = getLocalBounds().reduced(50);

    const int sliderWidth = 25;
    const int sliderHeight = 175;

    //draw sliders by reducing area from rectangle above
    attackSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    decaySlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    sustainSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));
    releaseSlider.setBounds(area.removeFromLeft(sliderWidth).removeFromTop(sliderHeight).withTrimmedTop(10));

}

void Envelope::sliderValueChanged(juce::Slider*)
{
}
