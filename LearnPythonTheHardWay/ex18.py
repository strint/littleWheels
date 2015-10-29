def print_two(*args):
    arg1, arg2 = args
    print "arg1: %r, arg2: %r" % (arg1, arg2)

def print_two_again(arg1, arg2):
    print "arg1: %r, arg2: %r" % (arg1, arg2)

def print_one():
    print "I got nothing!"

print_two("Zed", "Shaw")
print_two_again("Zed", "Shaw")
print_one()
