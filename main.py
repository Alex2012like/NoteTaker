import json
import os
from datetime import datetime

DATA_FILE = "tasks.json"

class Task:
    def __init__(self, task_id, title, description="", due_date=None, completed=False, created_at=None):
        self.task_id = task_id
        self.title = title
        self.description = description
        self.due_date = due_date
        self.completed = completed
        self.created_at = created_at if created_at else datetime.now().isoformat()

    def __str__(self):
        status = "[X]" if self.completed else "[ ]"
        due = f"(due {self.due_date})" if self.due_date else ""
        return f"{self.task_id}. {status} {self.title} {due}"

class TaskManager:
    def __init__(self, data_file):
        self.data_file = data_file
        self.tasks = self.load_tasks()
        self.next_id = self.get_next_id()

    def load_tasks(self):
        if os.path.exists(self.data_file):
            with open(self.data_file, "r") as f:
                try:
                    data = json.load(f)
                    return [Task(**task_data) for task_data in data]
                except json.JSONDecodeError:
                    return []
        return []

    def save_tasks(self):
        data = [task.__dict__ for task in self.tasks]
        with open(self.data_file, "w") as f:
            json.dump(data, f, indent=4)

    def get_next_id(self):
        if not self.tasks:
            return 1
        return max(task.task_id for task in self.tasks) + 1

    def add_task(self, title, description="", due_date=None):
        new_task = Task(self.next_id, title, description, due_date)
        self.tasks.append(new_task)
        self.save_tasks()
        self.next_id += 1
        print(f"Task '{title}' added with ID {new_task.task_id}.")

    def remove_task(self, task_id):
        try:
            task_id = int(task_id)
            self.tasks = [task for task in self.tasks if task.task_id != task_id]
            self.save_tasks()
            print(f"Task with ID {task_id} removed.")
        except ValueError:
            print("Please enter a valid task ID.")

    def complete_task(self, task_id):
        try:
            task_id = int(task_id)
            for task in self.tasks:
                if task.task_id == task_id:
                    task.completed = True
                    self.save_tasks()
                    print(f"Task with ID {task_id} marked as completed.")
                    return
            print(f"Task with ID {task_id} not found.")
        except ValueError:
            print("Please enter a valid task ID.")

    def list_tasks(self, show_completed=False):
        if not self.tasks:
            print("Task list is empty.")
            return

        print("\nTasks:")
        for task in self.tasks:
            if show_completed or not task.completed:
                print(task)
        if show_completed:
            print("\nAll tasks (including completed):")
            for task in self.tasks:
                print(task)

    def edit_task(self, task_id, new_title=None, new_description=None, new_due_date=None):
        try:
            task_id = int(task_id)
            for task in self.tasks:
                if task.task_id == task_id:
                    if new_title:
                        task.title = new_title
                    if new_description:
                        task.description = new_description
                    if new_due_date:
                        task.due_date = new_due_date
                    self.save_tasks()
                    print(f"Task with ID {task_id} updated.")
                    return
            print(f"Task with ID {task_id} not found.")
        except ValueError:
            print("Please enter a valid task ID.")

def main():
    task_manager = TaskManager(DATA_FILE)

    while True:
        print("\nChoose an action:")
        print("1. Add task")
        print("2. Remove task")
        print("3. Mark task as completed")
        print("4. Edit task")
        print("5. Show current tasks")
        print("6. Show all tasks")
        print("7. Exit")

        choice = input("> ")

        if choice == "1":
            title = input("Enter task title: ")
            description = input("Enter task description (optional): ")
            due_date_str = input("Enter due date in YYYY-MM-DD format (optional): ")
            due_date = due_date_str if due_date_str else None
            task_manager.add_task(title, description, due_date)
        elif choice == "2":
            task_id = input("Enter the ID of the task to remove: ")
            task_manager.remove_task(task_id)
        elif choice == "3":
            task_id = input("Enter the ID of the task to mark as completed: ")
            task_manager.complete_task(task_id)
        elif choice == "4":
            task_id = input("Enter the ID of the task to edit: ")
            new_title = input("Enter new title (leave blank to keep current): ")
            new_description = input("Enter new description (leave blank to keep current): ")
            new_due_date_str = input("Enter new due date in YYYY-MM-DD format (leave blank to keep current): ")
            new_due_date = new_due_date_str if new_due_date_str else None
            task_manager.edit_task(task_id, new_title, new_description, new_due_date)
        elif choice == "5":
            task_manager.list_tasks()
        elif choice == "6":
            task_manager.list_tasks(show_completed=True)
        elif choice == "7":
            print("Thank you for using the task manager!")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
