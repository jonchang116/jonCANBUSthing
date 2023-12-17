import re

def extract_can_data(line):
    match = re.search(r'can\d (\S+)', line)
    if match:
        return match.group(1)
    return None

def format_can_data(input_file, output_file):
    with open("driving.log", 'r') as f:
        lines = f.readlines()

    can_data_list = [extract_can_data(line) for line in lines if 'can' in line]

    with open(output_file, 'w') as f:
        for can_data in can_data_list:
            if can_data:
                f.write(f'"{can_data}",\n')

# Replace 'input.log' and 'output.log' with your actual file names
format_can_data('driving.log', 'simple.log')
