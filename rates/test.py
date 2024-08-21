import requests
import random

# Function to fetch problems from Codeforces API
def fetch_problems(min_rating, max_rating, num_problems):
    url = "https://codeforces.com/api/problemset.problems"
    response = requests.get(url)
    response.raise_for_status()
    data = response.json()
    
    problems = data['result']['problems']
    filtered_problems = [p for p in problems if 'rating' in p and min_rating <= p['rating'] <= max_rating]
    
    if len(filtered_problems) < num_problems:
        raise ValueError(f"Not enough problems found in the rating range {min_rating}-{max_rating}.")
    
    random_problems = random.sample(filtered_problems, num_problems)
    return random_problems

# Function to write problems to a file
def write_problems_to_file(problems, filename):
    with open(filename, 'w') as file:
        for problem in problems:
            problem_id = problem['contestId']
            problem_index = problem['index']
            problem_name = problem['name']
            problem_rating = problem.get('rating', 'N/A')  # Handle missing ratings gracefully
            problem_url = f"https://codeforces.com/problemset/problem/{problem_id}/{problem_index}"
            
            file.write(f"Problem Name: {problem_name}\n")
            file.write(f"Rating: {problem_rating}\n")
            file.write(f"URL: {problem_url}\n")
            file.write("\n")

# Main script
def main():
    min_rating = 1000
    max_rating = 1300
    num_problems = 10
    filename = 'codeforces_problems.txt'
    
    try:
        problems = fetch_problems(min_rating, max_rating, num_problems)
        write_problems_to_file(problems, filename)
        print(f"Saved {num_problems} problems to {filename}.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    main()
