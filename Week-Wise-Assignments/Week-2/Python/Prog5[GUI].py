import tkinter as tk
from tkinter import messagebox

PRIMARY_COLORS = ["Red", "Green", "Blue"]

class ColorSorterGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Color Sorter - Stack and Queue")
        self.root.geometry("600x400")

        self.stack = []
        self.queue = []

        self.color_input = tk.Entry(root, width=30)
        self.color_input.pack(pady=10)

        self.add_button = tk.Button(root, text="Add Color", command=self.sort_color)
        self.add_button.pack()

        self.stack_label = tk.Label(root, text="Primary Color Stack:", font=('Arial', 12, 'bold'))
        self.stack_label.pack(pady=(20, 0))
        self.stack_display = tk.Label(root, text="Empty", bg="white", width=50, relief="sunken")
        self.stack_display.pack()

        self.queue_label = tk.Label(root, text="Rejected Queue:", font=('Arial', 12, 'bold'))
        self.queue_label.pack(pady=(20, 0))
        self.queue_display = tk.Label(root, text="Empty", bg="white", width=50, relief="sunken")
        self.queue_display.pack()

        self.reset_button = tk.Button(root, text="Reset", command=self.reset)
        self.reset_button.pack(pady=10)

    def sort_color(self):
        color = self.color_input.get().strip()
        if not color:
            messagebox.showwarning("Input Error", "Please enter a color.")
            return

        if color in PRIMARY_COLORS:
            self.stack.append(color)
        else:
            self.queue.append(color)

        self.update_display()
        self.color_input.delete(0, tk.END)

    def update_display(self):
        self.stack_display.config(text=", ".join(self.stack) if self.stack else "Empty")
        self.queue_display.config(text=", ".join(self.queue) if self.queue else "Empty")

    def reset(self):
        self.stack = []
        self.queue = []
        self.update_display()
        self.color_input.delete(0, tk.END)

if __name__ == "__main__":
    root = tk.Tk()
    app = ColorSorterGUI(root)
    root.mainloop()
