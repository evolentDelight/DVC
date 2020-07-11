#!/Python37/python

import cgi
import headTail
import forms


def main():

    headTail.headHtml()
    forms.infoForm()
    headTail.tailHtml()

if __name__ == "__main__":

    try:
        password = forms.infoFormPass()

        if password != 'Password':
            forms.InvalidInput()
        else:
            main()

    except:

        cgi.print_exception()