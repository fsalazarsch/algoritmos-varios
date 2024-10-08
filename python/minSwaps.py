def minSwaps(s: str) -> int:

pos = [i for i, char in enumerate(s) if char == '[']
    count = 0 
    p = 0
    swaps = 0
    
    for i, char in enumerate(s):
        if char == '[':
            count += 1
            p += 1
        elif char == ']':
            count -= 1
        
        if count < 0:
            swaps += pos[p] - i  # Calculamos cuántos swaps necesitamos
            count = 1  # Restablecemos la cuenta después del intercambio
            p += 1
    
    return swaps
