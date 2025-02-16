#ifndef _detect_wake_word_state_h_
#define _detect_wake_word_state_h_

#include "States.h"
#include "RGBLED.h"

class I2SSampler;
class NeuralNetwork;
class AudioProcessor;
class RGBLED;

class DetectWakeWordState : public State
{
private:
    I2SSampler *m_sample_provider;
    NeuralNetwork *m_nn;
    RGBLED _rgb;
    AudioProcessor *m_audio_processor;
    float m_average_detect_time;
    int m_number_of_detections;
    int m_number_of_runs;

public:
    DetectWakeWordState(I2SSampler *sample_provider);
    void enterState();
    bool run();
    void exitState();
};

#endif
