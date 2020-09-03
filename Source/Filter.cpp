/*
  ==============================================================================

    Filter.cpp
    Created: 31 Aug 2020 8:42:03pm
    Author:  navan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Filter.h"

//==============================================================================
Filter::Filter(SynthFrameworkAudioProcessor& p) : audioProcessor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    setSize(200, 200);

    const auto oscTypeList = juce::StringArray("LP", "BP", "HP");
    filterTypeMenu.addItemList(oscTypeList, 1);
    filterTypeMenu.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&filterTypeMenu);

    filterTypeTree = make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.tree, "filtertype", filterTypeMenu);

    filterCutOffSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    filterCutOffSlider.setRange(0.0f, 22000.0f);
    filterCutOffSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&filterCutOffSlider);
    cutOffTree = make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "filtercutoff", filterCutOffSlider);
    filterCutOffSlider.setSkewFactorFromMidPoint(2000.0);

    filterResonanceSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    filterResonanceSlider.setRange(1.0f, 5.0f);
    filterResonanceSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&filterResonanceSlider);

    filterTypeTree = make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.tree, "filtertype", filterTypeMenu);
    resonanceTree = make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.tree, "filterresonance", filterResonanceSlider);
}

Filter::~Filter()
{
}

void Filter::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (juce::Colours::black);
}

void Filter::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

        // This method is where you should set the bounds of any child
    // components that your component contains..

    //draws the sliders...we use a rectangle object to dynamically size the UI (if we want to resize for IPad etc without needing to change ALL settings
    juce::Rectangle<int> area = getLocalBounds().reduced(40);

    //draw sliders by reducing area from rectangle above
    filterCutOffSlider.setBounds(30, 100, 70, 70);
    filterResonanceSlider.setBounds(100, 100, 70, 70);
    filterTypeMenu.setBounds(area.removeFromTop(20));



}
