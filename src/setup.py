#!/usr/bin/env python

"""
setup.py file for PDF gen
"""
import glob
from distutils.core import setup

setup(name='pdfGeneration',
      version='1.0',
      author = "IUPR",
      scripts = glob.glob("ocro*") + ["decapod-genpdf.py", "ocro2pdf.py", "fontGrouper.py", "DejaVuSans.sfd"],
      description = """PDF generation for Decapod
""",
      py_modules=['ocro2pdf','ocrodir'],
      )

