/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

namespace BinaryData
{

//================== README.md ==================
static const unsigned char temp_binary_data_0[] =
"```                                     \r\n"
"  _____ _____ ___   __ _  _____  __ __   __ ____  ____  \r\n"
" /     \\\\_   \\\\  \\/  /  |/     \\|  |  | |  \\_   \\/    \\\r\n"
"|  Y Y  \\/ /_ \\>    <|  |  Y Y  \\  |  |_|  |/ /_ \\  Y  \\\r\n"
"|__|_|  (___  /__/\\__\\__|__|_|  /__|____/__(___  /__|  /\r\n"
"      \\/    \\/                \\/               \\/    \\/\r\n"
"```\r\n"
"![version](https://img.shields.io/badge/version-2.2-red)\r\n"
"[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/mimic-sussex/eppEditor/blob/master/LICENSE)\r\n"
"\r\n"
"<br />\r\n"
"\r\n"
"### What's Maximilian?\r\n"
"\r\n"
"Maximilian is a cross-platform and multi-target audio synthesis and signal processing library. It was written in C++ and provides bindings to Javascript. It's compatible with native implementations for MacOS, Windows, Linux and iOS systems, as well a"
"s client-side browser-based applications. The main features are:\r\n"
"\r\n"
"- sample playback, recording and looping\r\n"
"- support for WAV and OGG files.\r\n"
"- a selection of oscillators and filters\r\n"
"- enveloping\r\n"
"- multichannel mixing for 1, 2, 4 and 8 channel setups\r\n"
"- controller mapping functions\r\n"
"- effects including delay, distortion, chorus, flanging\r\n"
"- granular synthesis, including time and pitch stretching\r\n"
"- atom synthesis\r\n"
"- real-time music information retrieval functions: spectrum analysis, spectral features, octave analysis, Bark scale analysis, and MFCCs\r\n"
"- example projects for Windows and MacOS, susing command line and OpenFrameworks environments\r\n"
"- example projects for Firefox and Chromium-based browsers using the Web Audio API ScriptProcessorNode (deprecated!)\r\n"
"- example projects for Chromium-based browsers using the Web Audio API AudioWorklet (e.g. Chrome, Brave, Edge, Opera, Vivaldi)\r\n"
"\r\n"
"\r\n"
"### Basic Examples\r\n"
"\r\n"
"You can choose between using RTAudio and PortAudio drivers in player.h by uncommenting the appropriate line.  To use PortAudio, you will need to compile the portAudio library from http://http://www.portaudio.com/ and link it with your executable.\r\n"
"\r\n"
"Examples demonstrating different features can be found in the maximilian_examples folder.  To try them, replace the contents of main.cpp with the contents of a tutorial file and compile.\r\n"
"\r\n"
"### Web Audio\r\n"
"\r\n"
"A transpiled javascript version of the library is included in this repository, for both Script Processor Nodes and AudioWorklets. Try this out at (https://mimicproject.com/guides/maximJS). \r\n"
"\r\n"
"\r\n"
"### Mac OS XCode Project\r\n"
"\r\n"
"You can run the examples using the 'maximilianTest' XCode 3 project provided.\r\n"
"\r\n"
"\r\n"
"### MS Windows Visual Studio Project\r\n"
"\r\n"
"This is in the maximilianTestWindowsVS2010 folder. You will need to install the DirectX SDK, so that the program can use DirectSound.\r\n"
"\r\n"
"\r\n"
"### Command Line Compilation in Mac OS\r\n"
"\r\n"
"> g++ -Wall -D__MACOSX_CORE__ -o maximilian main.cpp RtAudio.cpp player.cpp maximilian.cpp -framework CoreAudio -framework CoreFoundation -lpthread\r\n"
"\r\n"
"> ./maximilian\r\n"
"\r\n"
"\r\n"
"### Command Line Compilation in Linux\r\n"
"\r\n"
"With OSS:\r\n"
"> g++ -Wall -D__LINUX_OSS__ -o maximilian main.cpp RtAudio.cpp player.cpp maximilian.cpp -lpthread\r\n"
"\r\n"
"With ALSA:\r\n"
"> g++ -Wall -D__LINUX_ALSA__ -o maximilian main.cpp RtAudio.cpp player.cpp maximilian.cpp -lasound -lpthread\r\n"
"\r\n"
"With Jack:\r\n"
"> g++ -Wall -D__UNIX_JACK__ -o maximilian main.cpp RtAudio.cpp player.cpp maximilian.cpp `pkg-config --cflags --libs jack` -lpthread\r\n"
"\r\n"
"then:\r\n"
"> ./maximilian\r\n"
"\r\n"
"\r\n"
"\r\n"
"### OpenFrameworks Project\r\n"
"\r\n"
"Maximilian works well with the OpenFrameworks C++ creative coding toolkit (http://www.openframeworks.cc).\r\n"
"\r\n"
"In the ofxMaxim directory you will find examples to run in Windows, OSX and iOS, including FFT analysis and granular synthesis.  \r\n"
"\r\n"
"You can install the ofxMaxim addon by copying the ofxMaxim/ofxMaxim folder into your openframeworks addons directory.\r\n"
"\r\n"
"Important: when using Maximilian on OSX, link against the Accelerate framework.\r\n"
"\r\n"
"\r\n";

const char* README_md = (const char*) temp_binary_data_0;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x64791dc8:  numBytes = 3831; return README_md;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "README_md"
};

const char* originalFilenames[] =
{
    "README.md"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
    {
        if (namedResourceList[i] == resourceNameUTF8)
            return originalFilenames[i];
    }

    return nullptr;
}

}
