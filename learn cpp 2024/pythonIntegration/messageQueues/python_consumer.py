import subprocess

def main():
    # Run the C++ producer as a subprocess
    cpp_producer_process = subprocess.Popen(['./cpp_producer'], stdout=subprocess.PIPE, text=True)

    # Read messages from the C++ producer
    for _ in range(5):
        message = cpp_producer_process.stdout.readline().strip()
        print(f"Received from C++ producer: {message}")

    # Wait for the C++ producer to complete
    cpp_producer_process.wait()

if __name__ == "__main__":
    main()
