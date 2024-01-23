import subprocess
import time
import os

# Get the directory of the current script. Construct the path to the C++ program executable
script_directory = os.path.dirname(os.path.abspath(__file__))
cpp_program_path = os.path.join(script_directory, 'counting_cpp.exe')  # assuming the C++ program is compiled to counting_cpp.exe

# Ask the user for the increment value
increment = int(input("Enter increment value for C++ program: "))

start_time_python = time.time()

# Call the C++ program using subprocess and pass the increment value
process = subprocess.Popen([cpp_program_path], stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
output, _ = process.communicate(input=str(increment))

# Parse the output from C++ program
cpp_duration, cpp_final_count = map(int, output.split())

end_time_python = time.time()
duration_python = end_time_python - start_time_python

# Display results
print(f"C++ program execution time: {cpp_duration} milliseconds")
print(f"C++ program final count: {cpp_final_count}")
print(f"Python program duration: {duration_python:.6f} seconds.")
