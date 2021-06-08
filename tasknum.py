#!/usr/bin/env python3
variant = int(input("Variant: "))
tasks = int(input("Tasks: "))
print("+12:", variant % tasks, (variant + 12) % tasks)
print("+13:", variant % tasks, (variant + 13) % tasks)
print("Press Enter to exit...")
input()
