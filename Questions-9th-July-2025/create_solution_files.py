import os

# Define folder names and extensions with boilerplate templates
languages = {
    "C": {
        "ext": ".c",
        "boilerplate": '''#include <stdio.h>

int main() {
    // TODO: Implement solution here
    return 0;
}
'''
    },
    "Python": {
        "ext": ".py",
        "boilerplate": '''def main():
    # TODO: Implement solution here
    pass

if __name__ == "__main__":
    main()
'''
    },
    "Java": {
        "ext": ".java",
        "boilerplate": ''  # Will be generated dynamically below
    }
}

# Create folders and files
for lang, details in languages.items():
    folder = lang
    ext = details["ext"]

    # Create language folder if it doesn't exist
    os.makedirs(folder, exist_ok=True)

    for i in range(1, 186):  # 1 to 185 inclusive
        file_number = str(i).zfill(3)
        filename = f"{file_number}_question{ext}"
        filepath = os.path.join(folder, filename)

        if lang == "Java":
            # For Java class naming: prefix with 'Q' to avoid starting with digit
            class_name = f"Q{file_number}_question"
            boilerplate = f'''public class {class_name} {{
    public static void main(String[] args) {{
        // TODO: Implement solution here
    }}
}}
'''
            # Update filename to match class name
            filename = f"{class_name}{ext}"
            filepath = os.path.join(folder, filename)

        else:
            boilerplate = details["boilerplate"]

        # Write boilerplate code to file
        with open(filepath, "w") as f:
            f.write(boilerplate)

        print(f"Created: {filepath}")

print("✅ All 555 files created successfully with boilerplate code and valid Java class names.")
