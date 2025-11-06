#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000
#define MAX_TAG_LENGTH 50

struct Stack {
    char data[MAX_SIZE][MAX_TAG_LENGTH];
    int top;
};

// Initialize stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Check if stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push tag to stack
void push(struct Stack* stack, char* tag) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    strcpy(stack->data[++stack->top], tag);
}

// Pop tag from stack
void pop(struct Stack* stack, char* tag) {
    if (isEmpty(stack)) {
        strcpy(tag, "");
        return;
    }
    strcpy(tag, stack->data[stack->top--]);
}

// Peek top tag
void peek(struct Stack* stack, char* tag) {
    if (isEmpty(stack)) {
        strcpy(tag, "");
        return;
    }
    strcpy(tag, stack->data[stack->top]);
}

// Display stack contents
void displayStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Empty");
        return;
    }
    
    printf("Bottom -> ");
    for (int i = 0; i <= stack->top; i++) {
        printf("<%s> ", stack->data[i]);
    }
    printf("<- Top");
}

// Convert string to lowercase
void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Check if tag is self-closing
int isSelfClosingTag(char* tag) {
    char* selfClosingTags[] = {
        "br", "hr", "img", "input", "meta", "link", "area", "base", 
        "col", "embed", "source", "track", "wbr", "!doctype"
    };
    
    int numTags = sizeof(selfClosingTags) / sizeof(selfClosingTags[0]);
    
    char lowerTag[MAX_TAG_LENGTH];
    strcpy(lowerTag, tag);
    toLowerCase(lowerTag);
    
    for (int i = 0; i < numTags; i++) {
        if (strcmp(lowerTag, selfClosingTags[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Extract tag name from tag string (remove attributes)
void extractTagName(char* fullTag, char* tagName) {
    int i = 0, j = 0;
    
    // Skip '<' and potential '/'
    if (fullTag[i] == '<') i++;
    if (fullTag[i] == '/') i++;
    
    // Extract tag name until space or '>'
    while (fullTag[i] && fullTag[i] != ' ' && fullTag[i] != '>' && fullTag[i] != '/') {
        tagName[j++] = fullTag[i++];
    }
    tagName[j] = '\0';
    
    toLowerCase(tagName);
}

// Check if tag is closing tag
int isClosingTag(char* tag) {
    return (tag[0] == '<' && tag[1] == '/');
}

// Extract tags from HTML content
int extractTags(char* html, char tags[][MAX_TAG_LENGTH]) {
    int tagCount = 0;
    int len = strlen(html);
    int i = 0;
    
    while (i < len) {
        if (html[i] == '<') {
            int j = 0;
            int start = i;
            
            // Extract complete tag
            while (i < len && html[i] != '>') {
                i++;
            }
            
            if (i < len) { // Found closing '>'
                i++; // Include '>'
                
                // Copy tag
                int tagLen = i - start;
                strncpy(tags[tagCount], html + start, tagLen);
                tags[tagCount][tagLen] = '\0';
                
                tagCount++;
                if (tagCount >= MAX_SIZE) break;
            }
        } else {
            i++;
        }
    }
    
    return tagCount;
}

// Algorithm for HTML Validation:
// 1. Extract all HTML tags from the content
// 2. For each tag:
//    - If opening tag: push to stack (unless self-closing)
//    - If closing tag: check if matches top of stack
// 3. At end, stack should be empty for valid HTML
int validateHTML(char* html) {
    struct Stack stack;
    initStack(&stack);
    
    char tags[MAX_SIZE][MAX_TAG_LENGTH];
    int tagCount = extractTags(html, tags);
    
    printf("\n=== HTML Validation Process ===\n");
    printf("HTML Content: %s\n", html);
    printf("Algorithm: Use stack to match opening and closing HTML tags\n\n");
    
    printf("Extracted tags: %d\n", tagCount);
    for (int i = 0; i < tagCount; i++) {
        printf("Tag %d: %s\n", i + 1, tags[i]);
    }
    printf("\n");
    
    printf("Step-by-step validation:\n");
    
    for (int i = 0; i < tagCount; i++) {
        char tagName[MAX_TAG_LENGTH];
        extractTagName(tags[i], tagName);
        
        printf("Step %d: Processing tag '%s'\n", i + 1, tags[i]);
        printf("         Tag name: '%s'\n", tagName);
        
        if (isClosingTag(tags[i])) {
            printf("         Closing tag found\n");
            
            if (isEmpty(&stack)) {
                printf("         ERROR: No matching opening tag (stack is empty)\n");
                printf("         HTML is INVALID\n");
                return 0;
            }
            
            char topTag[MAX_TAG_LENGTH];
            peek(&stack, topTag);
            
            printf("         Top of stack: '%s'\n", topTag);
            
            if (strcmp(topTag, tagName) == 0) {
                char poppedTag[MAX_TAG_LENGTH];
                pop(&stack, poppedTag);
                printf("         Match found! Popped '%s' from stack\n", poppedTag);
            } else {
                printf("         ERROR: Mismatch! Expected '%s' but found '%s'\n", topTag, tagName);
                printf("         HTML is INVALID\n");
                return 0;
            }
        }
        else {
            if (isSelfClosingTag(tagName)) {
                printf("         Self-closing tag, not pushing to stack\n");
            } else {
                push(&stack, tagName);
                printf("         Opening tag, pushed '%s' to stack\n", tagName);
            }
        }
        
        printf("         Stack status: ");
        displayStack(&stack);
        printf("\n\n");
    }
    
    // Check if stack is empty at the end
    if (isEmpty(&stack)) {
        printf("Final check: Stack is empty - HTML is VALID\n");
        return 1;
    } else {
        printf("Final check: Stack is not empty - HTML is INVALID\n");
        printf("Unclosed tags: ");
        displayStack(&stack);
        printf("\n");
        return 0;
    }
}

// Validate HTML from file
int validateHTMLFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open file '%s'\n", filename);
        return 0;
    }
    
    char html[MAX_SIZE * 10];
    char line[MAX_SIZE];
    html[0] = '\0';
    
    printf("Reading HTML file: %s\n", filename);
    
    while (fgets(line, sizeof(line), file)) {
        strcat(html, line);
    }
    
    fclose(file);
    
    printf("File content loaded (%lu characters)\n", strlen(html));
    return validateHTML(html);
}

// Generate detailed HTML report
void generateHTMLReport(char* html) {
    printf("\n=== Detailed HTML Analysis Report ===\n");
    
    char tags[MAX_SIZE][MAX_TAG_LENGTH];
    int tagCount = extractTags(html, tags);
    
    int openingTags = 0, closingTags = 0, selfClosingTags = 0;
    
    printf("Tag Statistics:\n");
    printf("Total tags found: %d\n", tagCount);
    
    for (int i = 0; i < tagCount; i++) {
        char tagName[MAX_TAG_LENGTH];
        extractTagName(tags[i], tagName);
        
        if (isClosingTag(tags[i])) {
            closingTags++;
        } else if (isSelfClosingTag(tagName)) {
            selfClosingTags++;
        } else {
            openingTags++;
        }
    }
    
    printf("Opening tags: %d\n", openingTags);
    printf("Closing tags: %d\n", closingTags);
    printf("Self-closing tags: %d\n", selfClosingTags);
    
    printf("\nTag Balance Analysis:\n");
    if (openingTags == closingTags) {
        printf("✓ Opening and closing tags are balanced\n");
    } else {
        printf("✗ Tag imbalance detected!\n");
        printf("  Opening tags: %d, Closing tags: %d\n", openingTags, closingTags);
        printf("  Difference: %d\n", abs(openingTags - closingTags));
    }
}

int main() {
    char html[MAX_SIZE * 2];
    char filename[MAX_SIZE];
    int choice;
    
    printf("=== HTML Validation using Stack ===\n");
    printf("This program validates HTML tag structure using stack\n");
    printf("Checks for proper opening/closing tag matching\n");
    printf("Handles self-closing tags and case-insensitive matching\n\n");
    
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Validate HTML string\n");
        printf("2. Validate HTML file\n");
        printf("3. Test with sample HTML\n");
        printf("4. Generate detailed report\n");
        printf("5. Show algorithm explanation\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline
        
        switch (choice) {
            case 1:
                printf("Enter HTML string to validate: ");
                fgets(html, sizeof(html), stdin);
                html[strcspn(html, "\n")] = 0; // Remove newline
                
                if (strlen(html) == 0) {
                    printf("Empty HTML string!\n");
                    break;
                }
                
                int isValid = validateHTML(html);
                printf("\nResult: HTML is %s\n", isValid ? "VALID" : "INVALID");
                break;
                
            case 2:
                printf("Enter HTML filename: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                
                int fileValid = validateHTMLFile(filename);
                if (fileValid != -1) {
                    printf("\nResult: HTML file is %s\n", fileValid ? "VALID" : "INVALID");
                }
                break;
                
            case 3:
                printf("\n=== Sample HTML Tests ===\n");
                
                char* samples[] = {
                    "<html><body><h1>Hello</h1></body></html>",
                    "<div><p>Text</p><br></div>",
                    "<html><body><h1>Unclosed header</body></html>",
                    "<div><p>Nested <span>content</span></p></div>",
                    "<img src='image.jpg'><br><hr>",
                    "<div><p>Mismatched</div></p>",
                    "<!DOCTYPE html><html><head><title>Page</title></head><body></body></html>"
                };
                
                int numSamples = sizeof(samples) / sizeof(samples[0]);
                
                for (int i = 0; i < numSamples; i++) {
                    printf("\n--- Sample %d ---\n", i + 1);
                    strcpy(html, samples[i]);
                    int result = validateHTML(html);
                    printf("Result: %s\n", result ? "VALID" : "INVALID");
                }
                break;
                
            case 4:
                printf("Enter HTML string for detailed analysis: ");
                fgets(html, sizeof(html), stdin);
                html[strcspn(html, "\n")] = 0; // Remove newline
                
                if (strlen(html) == 0) {
                    printf("Empty HTML string!\n");
                    break;
                }
                
                generateHTMLReport(html);
                break;
                
            case 5:
                printf("\n=== Algorithm Explanation ===\n");
                printf("HTML Validation Algorithm:\n");
                printf("1. Extract all HTML tags from content\n");
                printf("2. For each tag:\n");
                printf("   - If opening tag: push tag name to stack\n");
                printf("   - If closing tag: check if matches top of stack\n");
                printf("   - If self-closing tag: ignore (don't push to stack)\n");
                printf("3. After processing: stack should be empty\n\n");
                
                printf("Special Considerations:\n");
                printf("- Case-insensitive tag matching\n");
                printf("- Self-closing tags (br, hr, img, etc.)\n");
                printf("- Tag attributes are ignored for matching\n");
                printf("- DOCTYPE declarations are treated as self-closing\n\n");
                
                printf("Time Complexity: O(n) - single pass through HTML\n");
                printf("Space Complexity: O(d) - d is maximum nesting depth\n");
                break;
                
            case 6:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}