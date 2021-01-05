class Clipboard:
    """
        Handles Copy and Paste actions
        and counts number of actions
        executed
    """

    def __init__(self):
        """
        --------------
        Method: __init__
        --------------
        Description:
            constructor
        Args:
            None
        --------------
        """
        self.__h = 1
        self.__clipboard = None
        self.__operations = 0

    def copy(self):
        """
        --------------
        Method: copy
        --------------
        Description:
            set 'clipboard' to
            the value of  'h'
            Increase 'operations'
            by 1
        Args:
            None
        --------------
        """
        self.__clipboard = self.__h
        self.__operations += 1

    def paste(self):
        """
        --------------
        Method: paste
        --------------
        Description:
            Increase value 'h' by
            the value store in
            'clipboard' and
            increase 'operations'
            by one
        Args:
            None
        --------------
        """
        self.__h += self.__clipboard
        self.__operations += 1

    def get_operations(self):
        """
        --------------
        Method: get_operations
        --------------
        Description:
            Return the number of
            operations executed
        Args:
            None
        --------------
        """
        return self.__operations
