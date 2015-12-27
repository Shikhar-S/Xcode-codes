//
//  ViewController.swift
//  FirstApp
//
//  Created by Shikhar  on 23/10/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

import UIKit
import AVFoundation

class ViewController: UIViewController,AVAudioRecorderDelegate {
    
    var Recorder:AVAudioRecorder!
    var recordedAudio:model!

    @IBOutlet weak var recordON: UILabel!
    
    @IBOutlet weak var StopButton: UIButton!
    @IBOutlet weak var RecordButton: UIButton!
   
    override func viewDidLoad() {
        super.viewDidLoad()
                // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    override func viewWillAppear(animated: Bool) {
        StopButton.hidden=true
        RecordButton.enabled=true
    }
    

    @IBAction func recordAudio(sender: UIButton) {
        RecordButton.enabled=false
        recordON.hidden=false
        StopButton.hidden=false
        
        
        let path=NSSearchPathForDirectoriesInDomains(.DocumentDirectory, .UserDomainMask, true)[0] as! String
        /*var currentDateTime=NSDate()
        var formatter=NSDateFormatter()
        formatter.dateFormat="ddMMyyyy-HHmmss"
        var recordingName=formatter.stringFromDate(currentDateTime)+".wav"*/
        var recordingName="my_audio.wav"
        var pathArray=[path,recordingName]
        let filePath=NSURL.fileURLWithPathComponents(pathArray)
        print(filePath)
        var session=AVAudioSession.sharedInstance()
        session.setCategory(AVAudioSessionCategoryPlayAndRecord, error: nil)
        
        Recorder=AVAudioRecorder(URL: filePath, settings: nil, error: nil)
        Recorder.delegate=self
        Recorder.meteringEnabled=true
        Recorder.prepareToRecord()
        Recorder.record()
        
    }
    func audioRecorderDidFinishRecording(recorder: AVAudioRecorder!, successfully flag: Bool) {
        if(flag)
        {
            recordedAudio=model()
            recordedAudio.path=recorder.url
            recordedAudio.title=recorder.url.lastPathComponent
            self.performSegueWithIdentifier("startNextView", sender: recordedAudio)
        }
        else
        {
            StopButton.hidden=true
            RecordButton.enabled=true
        }
        
    }
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        if(segue.identifier=="startNextView")
        {
            let calledview:ViewController2=segue.destinationViewController as! ViewController2
            calledview.received=sender as! model
    
        }
    }
    
    @IBAction func stopRecord(sender: UIButton) {
        recordON.hidden=true
        Recorder.stop()
        var audioSession=AVAudioSession.sharedInstance()
        audioSession.setActive(false, error: nil)
        
    }
}

