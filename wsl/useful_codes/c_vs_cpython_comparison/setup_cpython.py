from distutils.core import setup, Extension

module = Extension("Example", sources = ["./python.c"])

setup(name="PackageName",
      version="0.01",
      description="denem tanimi",
      ext_modules =[module]
     )
