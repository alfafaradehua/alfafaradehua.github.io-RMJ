import subprocess
import time
import os

# Get the directory of the current script. Construct the path to the C++ program executable
script_directory = os.path.dirname(os.path.abspath(__file__))
cpp_program_path = os.path.join(script_directory, 'count500M.exe')

start_time = time.time()

# Call the C++ program using subprocess
subprocess.run([cpp_program_path])

end_time = time.time()
duration = end_time - start_time

print(f"Calling the C++ program from Python took {duration:.6f} seconds.")





# if os.path.exists(cpp_program_path):
#     print("C++ executable found.")
# else:
#     print("C++ executable not found.")

# if os.access(cpp_program_path, os.R_OK | os.X_OK):
#     print("Python has read and execute permissions for the C++ executable.")
# else:
#     print("Python does not have sufficient permissions for the C++ executable.")
    