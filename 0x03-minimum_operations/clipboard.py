class Clipboard:

    def __init__(self):
        self.__h = 1
        self.__clipboard = None
        self.__operations = 0

    def copy(self):
        self.__clipboard = self.__h
        self.__operations += 1

    def paste(self):
        self.__h += self.__clipboard
        self.__operations += 1

    def get_h(self):
        return self.__h

    def get_clipboard(self):
        return self.__clipboard

    def get_operations(self):
        return self.__operations
