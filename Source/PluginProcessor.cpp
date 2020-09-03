/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessor::SynthFrameworkAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
    tree(*this, nullptr, "PARAMETERS",
        {std::make_unique<juce::AudioParameterFloat>("attack", "Attack", juce::NormalisableRange<float>(0.1f, 5000.0f), 0.1f, "Attack"),
        std::make_unique<juce::AudioParameterFloat>("decay", "Decay", juce::NormalisableRange<float>(1.0f, 2000.0f), 1.0f, "Decay"),
        std::make_unique<juce::AudioParameterFloat>("sustain", "Sustain", juce::NormalisableRange<float>(0.0f, 1.0f), 0.8f, "Sustain"), 
        std::make_unique<juce::AudioParameterFloat>("release", "Release", juce::NormalisableRange<float>(0.1f, 5000.0f), 0.1f, "Release"),
        std::make_unique<juce::AudioParameterFloat>("osctype", "OscType", juce::NormalisableRange<float>(0.0f, 2.0f), 0.0, "Osc Type"),
        std::make_unique<juce::AudioParameterFloat>("filtertype", "FilterType", juce::NormalisableRange<float>(0.0f, 2.0f), 0.0, "Filter Type"),
        std::make_unique<juce::AudioParameterFloat>("filtercutoff", "FilterCutOff", juce::NormalisableRange<float>(0.0f, 22000.2f), 400.0f, "Filter Cut Off"),
        std::make_unique<juce::AudioParameterFloat>("filterresonance", "FilterResonance", juce::NormalisableRange<float>(1.0f, 5.0f), 1.0f, "Filter Resonance")})
#endif
{

    mySynth.clearVoices();

    for (auto i = 0; i < numVoices; i++) {
        mySynth.addVoice(new SynthVoice());
    }

    mySynth.clearSounds();
    mySynth.addSound(new SynthSound());

}

SynthFrameworkAudioProcessor::~SynthFrameworkAudioProcessor()
{
}

//==============================================================================
const juce::String SynthFrameworkAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SynthFrameworkAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SynthFrameworkAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SynthFrameworkAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SynthFrameworkAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SynthFrameworkAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SynthFrameworkAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SynthFrameworkAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SynthFrameworkAudioProcessor::getProgramName (int index)
{
    return {};
}

void SynthFrameworkAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SynthFrameworkAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

    juce::ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    mySynth.setCurrentPlaybackSampleRate(lastSampleRate);

}

void SynthFrameworkAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SynthFrameworkAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SynthFrameworkAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    for (auto i = 0; i < mySynth.getNumVoices(); i++)
    {
        if ((myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i))))
        {
            myVoice->setOscType(tree.getRawParameterValue("osctype"));

            myVoice->setEnvParams(tree.getRawParameterValue("attack"),
                                  tree.getRawParameterValue("decay"),
                                  tree.getRawParameterValue("sustain"),
                                  tree.getRawParameterValue("release"));

            myVoice->setFilterParams(tree.getRawParameterValue("filtertype"),
                                    tree.getRawParameterValue("filtercutoff"),
                                    tree.getRawParameterValue("filterresonance"));
        }
    }
    buffer.clear();
    mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
   
}

//==============================================================================
bool SynthFrameworkAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* SynthFrameworkAudioProcessor::createEditor()
{
    return new SynthFrameworkAudioProcessorEditor (*this);
}

//==============================================================================
void SynthFrameworkAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SynthFrameworkAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SynthFrameworkAudioProcessor();
}
