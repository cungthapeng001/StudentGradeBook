import os
import glob
import re

def is_burmese(text):
    # Check if there are any characters in the Burmese unicode range (U+1000 - U+109F, AA60-AA7F, A9E0-A9FF)
    # Actually, any non-ascii in this context is likely Burmese
    return any(ord(c) > 127 for c in text)

def process_file(filepath):
    with open(filepath, 'r', encoding='utf-8') as f:
        lines = f.readlines()
    
    new_lines = []
    modified = False
    
    for line in lines:
        if '//' in line:
            idx = line.find('//')
            comment_part = line[idx:]
            code_part = line[:idx]
            
            if is_burmese(comment_part):
                modified = True
                if code_part.strip() == "":
                    # The whole line is a comment, skip it entirely
                    continue
                else:
                    # There is code before the comment, keep the code
                    new_lines.append(code_part.rstrip() + '\n')
            else:
                new_lines.append(line)
        else:
            new_lines.append(line)
            
    if modified:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.writelines(new_lines)
        print(f"Modified: {filepath}")

directory = r"c:\ProjectPBL"
for ext in ('*.c', '*.h'):
    for filepath in glob.glob(os.path.join(directory, ext)):
        process_file(filepath)

print("Done.")
