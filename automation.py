import os
import re
import datetime
import questionary

def main():
    number = questionary.text("Problem Number:").ask()
    if not number:
        return
        
    name = questionary.text("Problem Name:").ask()
    if not name:
        return
        
    date_input = questionary.text("Date (leave empty for today):").ask()
    if not date_input:
        date_str = datetime.datetime.now().strftime("%d %B %Y")
    else:
        date_str = date_input.strip()

    slug = re.sub(r'[^a-z0-9]+', '-', name.lower()).strip('-')
    link = f"https://leetcode.com/problems/{slug}"

    difficulty = questionary.select(
        "Difficulty:",
        choices=["Easy", "Medium", "Hard"]
    ).ask()
    if not difficulty:
        return

    tags = questionary.checkbox(
        "Tags (Space to select, Enter to confirm):",
        choices=[
            "Array", "String", "Hash Table", "Math", "Dynamic Programming", 
            "Sorting", "Greedy", "DFS", "BFS", "Tree", "Binary Tree", 
            "Binary Search", "Matrix", "Two Pointers", "Bit Manipulation", 
            "Stack", "Graph", "Prefix Sum", "Backtracking", "Trie", "Heap"
        ]
    ).ask()
    if tags is None:
        return

    complexities = [
        "O(1)", "O(log N)", "O(N)", "O(N log N)", "O(N^2)", "O(2^N)", "O(N!)", "Custom"
    ]
    
    tc = questionary.select("Time Complexity:", choices=complexities).ask()
    if tc == "Custom":
        tc = questionary.text("Enter Time Complexity:").ask()

    sc = questionary.select("Space Complexity:", choices=complexities).ask()
    if sc == "Custom":
        sc = questionary.text("Enter Space Complexity:").ask()

    filename = f"questions/{number}.cpp"
    
    if difficulty == "Easy":
        diff_str = "🟢 Easy"
    elif difficulty == "Medium":
        diff_str = "🟡 Medium"
    else:
        diff_str = "🔴 Hard"

    formatted_tags = ", ".join([f"`{t}`" for t in tags])

    header = f"/*\n * Problem: {number}. {name}\n * Link: {link}\n * Author: LatifY\n * Date: {date_str}\n * Time Complexity: {tc}\n * Space Complexity: {sc}\n */\n\n"

    if os.path.exists(filename):
        with open(filename, 'r', encoding='utf-8') as f:
            content = f.read()
        with open(filename, 'w', encoding='utf-8') as f:
            f.write(header + content)
        print(f"Prepended header to existing file: {filename}")
    else:
        with open(filename, 'w', encoding='utf-8') as f:
            f.write(header)
        print(f"Created new file: {filename}")

    readme_path = "README.md"
    table_header = "| # | Problem Name | Language | Difficulty | Tags |\n| :--- | :--- | :--- | :--- | :--- |\n"
    row = f"| {number} | {name} | [C++](./{filename}) | {diff_str} | {formatted_tags} |\n"

    if not os.path.exists(readme_path):
        with open(readme_path, 'w', encoding='utf-8') as f:
            f.write("# LeetCode Solutions\n\n")
            f.write(table_header)
            f.write(row)
        print("Created README.md and added entry.")
    else:
        with open(readme_path, 'a', encoding='utf-8') as f:
            f.write(row)
        print("Appended entry to README.md.")

if __name__ == "__main__":
    main()