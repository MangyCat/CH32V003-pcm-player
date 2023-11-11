from scipy.io import wavfile
import numpy as np
inputf = input("Audio file: ")
# Read the audio file
sample_rate, audio_data = wavfile.read(str(inputf))

# Normalize audio data to the range of 0-255
normalized_data = (audio_data - np.min(audio_data)) * (255.0 / np.max(audio_data))

# Convert to 8-bit unsigned integers
pcm_array = normalized_data.astype(np.uint8)

# Output the array in the desired format for Arduino
array_name = "audioData"

array_string = f"const unsigned char {array_name}[] PROGMEM = {{"

for value in pcm_array:
    array_string += f"{value}, "

array_string = array_string[:-2]  # Remove the extra comma and space from the last element
array_string += "};"

# Output the array string
print(array_string)
