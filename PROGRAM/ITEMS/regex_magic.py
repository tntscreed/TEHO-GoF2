import re

def add_to_items_number(text):
    # Function to add 100 to the captured number
    return re.sub(r'(ITEMS_)(\d+)', lambda match: f"{match.group(1)}{int(match.group(2)) + 100}", text)

# Examples
print(add_to_items_number("ITEMS_12 ITEMS_1"))  # ITEMS_112