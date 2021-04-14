#!/usr/bin/python3

class TheRain():
    """
        Find the space between the walls
    """
    _COLLECTED = 0

    def __init__(self, walls):
        """ constructor """
        self.walls = walls.copy()
        self._tallest_wall = max(walls)
        self._levels = []

    def _find_levels(self):
        """ find water levels """
        for height in range(self._tallest_wall, 0, -1):
            level = []
            for index, wall in enumerate(self.walls):
                if wall >= height:
                    level.append(str(index))
                else:
                    level.append(' ')
            self._levels.append(level.copy())

    def falls(self):
        """ Finds space between walls """
        self._find_levels()
        print(self.walls)
        for level in self._levels:
            s1 = "".join(level)
            print(s1.replace(' ', '_'))
            s1 = s1.strip()
            # print(s1.replace(' ', '_'))
            self._COLLECTED += s1.count(' ')
        return self._COLLECTED


def rain(walls):
    """ rain function """
    if walls == []:
        return 0

    the_rain = TheRain(walls)
    result = the_rain.falls()
    return result
