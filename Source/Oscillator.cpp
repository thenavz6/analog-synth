/*
  ==============================================================================

    Oscillator.cpp
    Created: 29 Aug 2020 6:08:05pm
    Author:  navan

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(SynthFrameworkAudioProcessor& p) : 
    audioProcessor(p),
    oscMenuTree()
{ 

    setSize(200, 200);
    const auto oscTypeList = juce::StringArray("Sin", "Saw", "Sqr");
    oscMenu.addItemList(oscTypeList, 1);
    oscMenu.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(&oscMenu);

    oscMenuTree = make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.tree, "osctype", oscMenu);

}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (juce::Graphics& g)
{
    
}

void Oscillator::resized()
{
    
    juce::Rectangle<int> area = getLocalBounds().reduced(40);

    oscMenu.setBounds(area.removeFromTop(20));

}

void Oscillator::comboBoxChanged(juce::ComboBox*)
{
}
