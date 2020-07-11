#!/python37/python

import cgi
import headTail
import forms

def main():
    headTail.headHtml()
    forms.login()
    headTail.tailHtml()


if __name__ == "__main__":

        try:

         main()

        except:

            cgi.print_exception()