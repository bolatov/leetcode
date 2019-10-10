class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        """
        Check if area of a triangle, given by three points,
        is empty. Valid boomerang has non-empty area.
        """
        
        def get_line_length(x1, y1, x2, y2):
            """Pythagorian theorem."""
            return ((x2-x1)**2 + (y2-y1)**2) ** 0.5
        
        def get_area(a, b, c):
            """Heron's Formula."""
            s = (a+b+c)/2
            area = (s * (s-a) * (s-b) * (s-c)) ** 0.5
            return area
        
        lines = [
            get_line_length(*points[0], *points[1]),
            get_line_length(*points[1], *points[2]),
            get_line_length(*points[0], *points[2]),
        ]
        return get_area(*lines)
