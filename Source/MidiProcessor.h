/*
  ==============================================================================

    MidiProcessor.h
    Created: 12 Jun 2025 12:06:45pm
    Author:  Gtiez

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class MidiProcessor
{

public:
  void process(juce::MidiBuffer &midiMessages)
  {
    processedBuffer.clear();

    juce::MidiBuffer::Iterator it(midiMessages);
    juce::MidiMessage currentMessage;

    int samplePosition;

    while (it.getNextEvent(currentMessage, samplePosition))
    {
      if (currentMessage.isNoteOnOrOff())
      {
        auto transposedMessage = currentMessage;
        auto oldNoteNumber = transposedMessage.getNoteNumber();

        transposedMesssage.setNoteNumber(oldNumber + 4);
        processdBuffer.addEvent(transposedMessage, samplePosition);

        currentMessage.setNoteNumber(50);

        DBG(currentMessage.getDescription());
        DBG(currentMessage.getNoteNumber());
      }

      processedBuffer.addEvent(currentMessage, samplePosition);
    }

    midiMessages.swapWith(processedBuffer);
  }

  juce::MidiBuffer processedBuffer;
};
