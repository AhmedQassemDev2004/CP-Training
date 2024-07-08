import os
import logging

# Configure logging to output to the console
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(levelname)s - %(message)s')

# Define the function to check if a file is a C++ file
def valid(file_name):
    valid_extensions = ('.cpp', '.hpp', '.h', '.c', '.cc', '.py', '.clang-format')
    return file_name.endswith(valid_extensions)

# Define the function to remove non-C++ files
def remove_non_valid_files(directory):
    logging.debug(f'Starting to clean directory: {directory}')
    for root, dirs, files in os.walk(directory):
        logging.debug(f'Entering directory: {root}')
        for file in files:
            file_path = os.path.join(root, file)
            if not valid(file):
                try:
                    os.remove(file_path)
                    logging.info(f'Removed file: {file_path}')
                except Exception as e:
                    logging.error(f'Error removing file {file_path}: {e}')
            else:
                logging.info(f'Kept file: {file_path}')

if __name__ == "__main__":
    directory_to_clean = input("Enter path: ")
    if not os.path.isdir(directory_to_clean):
        logging.error(f'The provided path is not a directory: {directory_to_clean}')
    else:
        remove_non_valid_files(directory_to_clean)
