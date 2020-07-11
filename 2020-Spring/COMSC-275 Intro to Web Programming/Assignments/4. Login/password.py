#!/Python37/python

import cgi
import headTail
import forms

def main():

    headTail.headHtml()
    forms.password()
    headTail.tailHtml()


if __name__ == "__main__":

    try:
         login = forms.infoFormLogin()

         if login != 'Login':
             forms.InvalidInput()
         else:
            main()

    except:

        cgi.print_exception()