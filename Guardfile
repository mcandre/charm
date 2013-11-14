guard :shell do
  watch('Makefile|.*\.(c|h)') do |m|
    title = 'Test'
    msg = `make`
    status = ($?.success? && :success) || :failed

    n msg, title, status
    "-> #{msg}"
  end
end
