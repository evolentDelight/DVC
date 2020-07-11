#! /Python27/python

import cgi

from headTail import headHtml

from headTail import tailHtml

from forms import dispForm


def main():
    headHtml()
    dispForm()

    tailHtml()
    return


if __name__ == "__main__":

    try:

        main()

    except:

        cgi.print_exception()

