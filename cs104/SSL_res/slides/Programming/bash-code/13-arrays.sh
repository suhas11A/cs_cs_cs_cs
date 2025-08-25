#!/usr/bin/env bash
# --- Indexed Array ---
echo "### Indexed Array Example ###"

# Declare an indexed array
fruits=("Apple" "Banana" "Cherry")

# Add an element at index 3
fruits[3]="Orange"

# Print all elements
echo "All Fruits: ${fruits[@]}"

# Print the length of the array
echo "Number of Fruits: ${#fruits[@]}"

# Loop through the indexed array
echo "List of Fruits:"
for fruit in "${fruits[@]}"; do
    echo "$fruit"
done

# Remove an element
unset fruits[1]
echo "After removing Banana: ${fruits[@]}"
echo ""

# --- Associative Array ---
echo "### Associative Array Example ###"

# Declare an associative array (Requires declare -A)
declare -A capitals

# Assign values
capitals["France"]="Paris"
capitals["Japan"]="Tokyo"
capitals["USA"]="Washington D.C."
capitals["India"]="New Delhi"

# Print all keys
echo "Countries: ${!capitals[@]}"

# Print all values
echo "Capitals: ${capitals[@]}"

# Access a single value
echo "Capital of India: ${capitals["India"]}"

# Loop through the associative array
echo "Country - Capital List:"
for country in "${!capitals[@]}"; do
    echo "$country - ${capitals[$country]}"
done

# Remove an element
unset capitals["USA"]
echo "After removing USA: ${!capitals[@]}"

