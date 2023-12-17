import re

def decode_can_message(log_entry):
    # Define the regular expression pattern for extracting relevant information
    pattern = re.compile(r'\(([^)]+)\) (\S+) (\S+)')
    match = pattern.search(log_entry)

    if match:
        timestamp, interface_name, hex_data = match.groups()

        # Assuming 8 bytes of hexadecimal data
        raw_data = bytes.fromhex(hex_data[1:])

        # Perform decoding logic based on your specifications
        # Example: print raw data
        print("Timestamp:", timestamp)
        print("Interface:", interface_name)
        print("Hex Data:", hex_data)
        print("Decoded Data:", raw_data)
        print()

def main():
    log_file_path = "D:/canbus hsit/driving.log"

    with open(log_file_path, 'r') as file:
        for line in file:
            decode_can_message(line)

if __name__ == "__main__":
    main()
