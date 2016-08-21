##
## Uuid Test
##

assert("Uuid#hello") do
  t = Uuid.new "hello"
  assert_equal("hello", t.hello)
end

assert("Uuid#bye") do
  t = Uuid.new "hello"
  assert_equal("hello bye", t.bye)
end

assert("Uuid.hi") do
  assert_equal("hi!!", Uuid.hi)
end
