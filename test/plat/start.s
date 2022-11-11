

.global start

start:
	ldr x0,=stack_top
	mov sp,x0

	bl main
	b  end

end:
	mov x0,x0
	b end

