function sec(arr){
    arr = arr.split(":");
    arr = Number(arr[0]) *60 + Number(arr[1]);
    return arr;
}


function solution(video_len, pos, op_start, op_end, commands) {
    let answer = [];
    video_len =sec(video_len);
    pos = sec(pos);
    op_start = sec(op_start);
    op_end = sec(op_end);
    
    commands.forEach((order) => {
        if(pos>=op_start && pos<op_end){
            pos = op_end;
        }
        switch(order){
            case "next":
                pos +=10;
                if (pos > video_len) pos = video_len;
                break;
                
            case "prev":
                pos-=10;
                if(pos<0) pos=0;
                break;
        }
    });
    
    if(pos>=op_start && pos<op_end){
            pos = op_end;
        }
    
    answer.push(String(Math.floor(pos / 60)).padStart(2, "0"));
    answer.push(String(pos % 60).padStart(2, "0"));
    
    return answer.join(":");
}