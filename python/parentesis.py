class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {')': '(', '}': '{', ']': '['}

        for char in s:
            if char in mapping:
                top_element = stack.pop() if stack else '#'
                if mapping[char] != top_element:
                    return False
            else:
                stack.append(char)

        return not stack


import unittest

class TestSolution(unittest.TestCase):
    def test_valid_string(self):
        solution = Solution()
        self.assertTrue(solution.isValid("(([]){[()[]]})"))

    def test_invalid_string(self):
        solution = Solution()
        self.assertFalse(solution.isValid("({]}])"))

    def test_another_valid_string(self):
        solution = Solution()
        self.assertTrue(solution.isValid("{[()]()}"))

    def test_empty_string(self):
        solution = Solution()
        self.assertTrue(solution.isValid(""))

    def test_string_with_text(self):
        solution = Solution()
        self.assertTrue(solution.isValid("Este es un (texto) de prueba."))

    def test_string_with_parentheses_brackets_and_braces(self):
        solution = Solution()
        self.assertTrue(solution.isValid("[](){}"))

if __name__ == '__main__':
    unittest.main()
