#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>

class SimpleWavReader {
public:
    SimpleWavReader(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);

        if (!file.is_open()) {
            std::cerr << "Failed to open WAV file: " << filename << std::endl;
            return;
        }

        // Read WAV header
        file.read(reinterpret_cast<char*>(&header), sizeof(header));

        if (file.gcount() != sizeof(header)) {
            std::cerr << "Error reading WAV header." << std::endl;
            return;
        }

        // Check if the file is a valid WAV file
        if (std::memcmp(header.chunkId, "RIFF", 4) != 0 || std::memcmp(header.format, "WAVE", 4) != 0 || header.subchunk1Size != 16 || header.audioFormat != 1) {
            std::cerr << "Invalid or unsupported WAV file." << std::endl;
            return;
        }

        // Read audio data
        audioData.resize(header.subchunk2Size / sizeof(short));
        file.read(reinterpret_cast<char*>(audioData.data()), header.subchunk2Size);
    }

    std::vector<short> getAudioData() const {
        return audioData;
    }

    int getSampleRate() const {
        return header.sampleRate;
    }

    int getNumChannels() const {
        return header.numChannels;
    }

private:
    struct WavHeader {
        char chunkId[4];
        uint32_t chunkSize;
        char format[4];
        char subchunk1Id[4];
        uint32_t subchunk1Size;
        uint16_t audioFormat;
        uint16_t numChannels;
        uint32_t sampleRate;
        uint32_t byteRate;
        uint16_t blockAlign;
        uint16_t bitsPerSample;
        char subchunk2Id[4];
        uint32_t subchunk2Size;
    };

    WavHeader header;
    std::vector<short> audioData;
};

int main(int argc, char* argv[]) {
    std::string input = "./audiosuite/samples/";
    if (argc > 1) { 
        input += argv[1];
        input += ".wav"; 
    } else { input += "mixkit-retro-game-over.wav"; }
    
    // Instantiate Audio Module 
    SimpleWavReader wavReader(input);

    // Access audio data and other information
    if (!wavReader.getAudioData().empty()) {
        std::cout << "Sample Rate: " << wavReader.getSampleRate() << " Hz\n";
        std::cout << "Channels: " << wavReader.getNumChannels() << "\n";

        // Sample some audio data (for demonstration purposes)
        for (int i = 0; i < std::min(10, static_cast<int>(wavReader.getAudioData().size())); ++i) {
            std::cout << "Sample " << i << ": " << wavReader.getAudioData()[i] << "\n";
        }
    }

    return 0;
}
