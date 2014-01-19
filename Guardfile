guard :shell do
  watch(/Makefile|(.*\.(c|h))/) do |m|
    title = 'Test'
    eager 'make'
    status = ($?.success? && :success) || :failed
    n '', title, status
    ''
  end
end
