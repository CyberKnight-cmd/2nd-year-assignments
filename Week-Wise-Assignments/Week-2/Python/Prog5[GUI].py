import tkinter as tk
from tkinter import messagebox

PRIMARY_COLORS = ["Red", "Green", "Blue"]

class ColorSorterApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Color Sorter")

        self.stack = []
        self.queue = []

        self.setup_widgets()

    def setup_widgets(self):
        self.input_label = tk.Label(self.root, text="Enter a color:")
        self.input_label.pack()

        self.color_entry = tk.Entry(self.root)
        self.color_entry.pack()

        self.submit_btn = tk.Button(self.root, text="Add Color", command=self.process_color)
        self.submit_btn.pack()

        self.stack_label = tk.Label(self.root, text="Primary Color Stack:")
        self.stack_label.pack()

        self.stack_frame = tk.Frame(self.root)
        self.stack_frame.pack(pady=5)

        self.queue_label = tk.Label(self.root, text="Non-primary Color Queue:")
        self.queue_label.pack()

        self.queue_frame = tk.Frame(self.root)
        self.queue_frame.pack(pady=5)

        self.reset_btn = tk.Button(self.root, text="Reset", command=self.reset)
        self.reset_btn.pack(pady=10)

    def process_color(self):
        color = self.color_entry.get().strip()
        if not color:
            messagebox.showwarning("Input Error", "Please enter a color.")
            return

        if color in PRIMARY_COLORS:
            self.stack.append(color)
            self.display_stack()
        else:
            self.queue.append(color)
            self.display_queue()

        self.color_entry.delete(0, tk.END)

    def display_stack(self):
        for widget in self.stack_frame.winfo_children():
            widget.destroy()
        for color in reversed(self.stack):
            tk.Label(self.stack_frame, text=color, bg=color if color in PRIMARY_COLORS else "white", width=15).pack()

    def display_queue(self):
        for widget in self.queue_frame.winfo_children():
            widget.destroy()
        for color in self.queue:
            tk.Label(self.queue_frame, text=color, bg="white", fg="black", width=15).pack()

    def reset(self):
        self.stack = []
        self.queue = []
        self.display_stack()
        self.display_queue()
        self.color_entry.delete(0, tk.END)

if __name__ == "__main__":
    root = tk.Tk()
    app = ColorSorterApp(root)
    root.mainloop()