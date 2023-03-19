BEGIN{
drop = 0;
}
If($1=="d")
{
drop++;
}
END{
printf("The number of %s packets dropped due to congestion = %d\n",$5,drop);
}
